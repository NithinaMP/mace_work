// import React from "react";
// function StudentList(){
//     const students=[
//         {id:1,name:"John"},
//         {id:2,name:"Emily"},
//         {id:3,name:"Michael"},
//         {id:4,name:"Mickey"},
//         {id:5,name:"Sophia"},
//     ];
//     return(
//         <div><h2>Student List</h2>
//         <ul>
//             {students.map((student)=>(
//                 <li key={student.id}>
//                     {student.id}-{student.name}
//                 </li>
//             ))}</ul></div>
//     )
// }
// export default StudentList;

// import React, { useState } from "react";

// function UserInputExample() {
//   // Step 1: Create a state variable to store the input value
//   const [name, setName] = useState("");

//   // Step 2: Handle the input change
//   const handleChange = (event) => {
//     setName(event.target.value);
//   };

//   return (
//     <div style={{ textAlign: "center", marginTop: "50px" }}>
//       <h2>Enter Your Name:</h2>

//       {/* Step 3: Add input field and bind it with state */}
//       <input
//         type="text"
//         value={name}
//         onChange={handleChange}
//         placeholder="Type your name"
//       />

//       {/* Step 4: Show the value */}
//       <h3>Hello, {name || "Stranger"} 👋</h3>
//     </div>
//   );
// }

// export default UserInputExample;



import React, { useState } from "react";

function WordList() {
  const [word, setWord] = useState("");
  const [words, setWords] = useState([]);

  const handleAddWord = () => {
    if (word.trim() !== "") {
      setWords([...words, word]); // add the new word to array
      setWord(""); // clear input
    }
  };
    const handleKeyPress = (e) => {
    if (e.key === "Enter") {
      handleAddWord();
    }
  };

  return (
    <div style={{ textAlign: "center", marginTop: "50px" }}>
      <h2>Type a word</h2>
      <input
  type="text"
  value={word}
  onChange={(e) => setWord(e.target.value)}
  onKeyDown={handleKeyPress}
  placeholder="Enter a word"
/>

      <button onClick={handleAddWord}>Add</button>

      <h3>Words you entered:</h3>
      <ul>
        {words.map((w, index) => (
          <li key={index}>{w}</li>
        ))}
      </ul>
    </div>
  );
}

export default WordList;
