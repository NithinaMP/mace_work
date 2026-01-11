const mysql = require('mysql2');

const con = mysql.createConnection(
   { host : 'localhost',
    user :'root',
    password : 'add'
});

con.connect((err)=>{
    if (err) throw err;
    console.log("Connected.");
    // con.query("CREATE DATABASE IF NOT EXISTS clgDB",(err)=>{
    //     if(err) throw err;
    //     console.log("Database created");
    //     con.end();
    // });

const createTable= `
    CREATE TABLE IF NOT EXISTS stud(
    id INT PRIMARY KEY,
    name VARCHAR(20),
    age INT ,
    course VARCHAR(20)
    )
    `;



    con.query(createTable,(err)=>{
        if (err) throw err;
        console.log("Table created.")
        con.end();
    });
});




























// const mysql = require("mysql2");

// const connection = mysql.createConnection({
//   host: "localhost",
//   user: "root",        
//   password: "add"      
// });

// connection.connect((err) => {
//   if (err) throw err;
//   console.log("Connected to MySQL!");

//   connection.query("CREATE DATABASE IF NOT EXISTS CollegeDB", (err) => {
//     if (err) throw err;
//     console.log(" Database 'CollegeDB' created or already exists.");

//     // Switch to the CollegeDB database
//     connection.changeUser({ database: "CollegeDB" }, (err) => {
//       if (err) throw err;

//       // Step 2: Create Table Students
//       const createTableQuery = `
//         CREATE TABLE IF NOT EXISTS Students (
//           id INT PRIMARY KEY,
//           name VARCHAR(50),
//           age INT,
//           course VARCHAR(30)
//         )
//       `;

//       connection.query(createTableQuery, (err) => {
//         if (err) throw err;
//         console.log("📘 Table 'Students' created successfully!");

//         // Step 3: Insert sample data
//         const insertQuery = `
//           INSERT INTO Students (id, name, age, course)
//           VALUES (1, 'John Doe', 20, 'Computer Science'),
//                  (2, 'Anna Smith', 21, 'Electronics')
//           ON DUPLICATE KEY UPDATE name=VALUES(name);
//         `;

//         connection.query(insertQuery, (err) => {
//           if (err) throw err;
//           console.log("✅ Sample data inserted!");

//           // Step 4: Display table contents
//           connection.query("SELECT * FROM Students", (err, results) => {
//             if (err) throw err;
//             console.log("📊 Students Table:");
//             console.table(results);

//             // Close connection
//             connection.end();
//           });
//         });
//       });
//     });
//   });
// });
