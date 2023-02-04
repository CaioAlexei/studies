//imports
const express = require('express')
const app = express()
const mongoose = require('mongoose')
const cors = require('cors')
require('dotenv').config()

//middlewares
app.use(cors())
app.use(express.static('public'))
app.use(express.urlencoded({extended: true}))


// database
mongoose.set('strictQuery', true)
try{
  mongoose.connect(process.env.MONGO_URI, { useNewUrlParser: true, useUnifiedTopology: true });
}catch{
  console.log("Database connection Failed");
}

// ------- Schemas -----------

// User Schema
let userSchema = new mongoose.Schema({
  username:{
      type: String,
      unique: true
  }
},{versionKey: false});

// Exercise Schema
let exerciseSchema = new mongoose.Schema({

  username:{
    type: String,
    required:true
  },
  description:{
    type:String,
    required: true
  },
  duration:{
    type:Number,
    required: true
  },
  date:{
    type: Date
  }
  
  
},{versionKey: false});


// Creating Models
let User = mongoose.model('User', userSchema);
let Exercise = mongoose.model('Exercise',exerciseSchema);



// routes
app.get('/', (req, res) => {
  res.sendFile(__dirname + '/views/index.html');
});
// routes api

app.get('/api/users', async (req, res) => {

  const userslist = await User.find()
  return res.json(userslist);

});

app.post('/api/users', async (req,res) => {
  
  const username = req.body.username;
  const user = await User.create({username:username});
  return res.json(user);
});
app.get('/api/users/:_id/logs', async (req, res) => {
  const from = req.query.from;
  const to = req.query.to;
  const limit = +req.query.limit;
  const foundUser = await User.findOne({_id:mongoose.Types.ObjectId(req.params._id)})
   if(!foundUser){
     return res.json({res:"User do not exist"})
   }
  let exerciseList;
  if(from && to){
    const datefrom = new Date(from);
    const dateto = new Date(to);
    exerciseList = await Exercise.find({
      username:foundUser.username,
      date:{
        $gte: datefrom.toDateString(),
        $lt: dateto.toDateString()
      }
      
    })
  }else if(limit){
    exerciseList = await Exercise.find({username:foundUser.username}).limit(limit);

  }else{
    exerciseList = await Exercise.find({username:foundUser.username});
  }   
  
  
  exerciseList = exerciseList.map((exercises)=>{
    return{
      description: exercises.description,
      duration: exercises.duration,
      date: exercises.date.toDateString(),
    };
  });
  
  const objectFinal = {
    username:foundUser.username,    
    count:exerciseList.length,
    _id:foundUser._id,
    log:exerciseList
      
  }
  
  res.json(objectFinal);
})
app.post('/api/users/:id/exercises', async (req, res) => {
  //post body data
  const _id = req.params.id;
  const userResult = await User.findOne(mongoose.Types.ObjectId(_id))
  const username = userResult.username;
  const description = req.body.description;
  const duration = +req.body.duration;
  let date = req.body.date;

  if (date === "" || date ===undefined){
    date = new Date();    
  }else{
    console.log("data inicial: "+ date)
    date = new Date(date);
    console.log(date)
  }
  if(date =="Invalid Date"){
    return res.json({res:"Invalid Date"});
  }
  console.log(typeof(date.toDateString()))
  const exerciseObject = {
    username: username,
    description: description,
    duration: duration,
    date: date.toDateString(),
    userid: _id
  }

  
  const exercise = await Exercise.create(exerciseObject);
  
  return res.json({
    username: username,
    description: description,
    duration: duration,
    date: date.toDateString(),
    _id: _id
  })
  
})

// listener
const listener = app.listen(process.env.PORT || 3001, () => {
  console.log('Your app is listening on port ' + listener.address().port)
});

