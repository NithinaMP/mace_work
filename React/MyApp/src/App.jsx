// import { useState } from 'react'
// import reactLogo from './assets/react.svg'
// import viteLogo from '/vite.svg'
// import './App.css'
// // import Pgm1 from './pgm1'
import React from 'react';
// import ListItems from './list';
// import Child from './child';
// import Button from './button';
import "./App.css";


//THIS IS PARENT AND CLASS FUNCTION CODE

// function App() {
//   const showMessage=() =>{
//     alert ("This message is from parent class ...okay!")
//   };
//   // const [count, setCount] = useState(0)

//   return (
//     // <div className='app-root'>
//     //   <StudentList/>
//     // </div>
//     <div>
//       <Child handleClick = {showMessage}/>
//       {/* <ListItems /> */}
//     </div>
//   );
// }

// PARENT AND CHILD CLASS CALLING

// function App() {
//   function handleClick(){
//     alert("Clicked")
//   }
//   return (
//     <div>
//       <h2>Reusable button</h2>
//       <Button text="Click Me" onClick={handleClick}/>
//       <Button text="Save" bg="green" onClick={()=>alert("SAVED!")}/>
//         <Button text="Delete" bg="red" onClick={()=>alert("DELETED")}/>
//     </div>
//   )
// }


import {BrowserRouter,Routes,Route, Link} from "react-router-dom";
import About from './Router/about';
import Home from './Router/home';
import Contact from './Router/contact';
function App() {
  return (
    <>
    <BrowserRouter>
    <nav style={{gap:"20px", display:"flex"}}>
      <Link to='/'>Home</Link>
      <Link to='/about'>About</Link>
      <Link to='/contact'>Contact</Link>
      </nav>
      <Routes>
        <Route path="/" element={<Home />}/>
        <Route path="/about" element={<About/>} />
        <Route path="/contact" element={<Contact/>}/> 
      </Routes>
      </BrowserRouter>
    </>
  )
}

export default App;
// export default App;rfce