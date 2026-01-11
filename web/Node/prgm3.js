// const con = require('./prgm1.js');
//  const sql= "INSERT INTO T_db.students(rollno,name) VALUES (5,'Ram')";
//  con.query(sql,(err,result)=>{
//     if(err) throw err;
//     console.log('Record inserted successfully');
//  });




const con = require('./prgm1.js');
const sql = "INSERT INTO T_db.students(rollno, name) VALUES ?";
const studentsToInsert = [
    [11, 'Priya Sharma'],
    [22, 'Mike Davis'],
    [82, 'Sarah Lee']
];

con.query(sql, [studentsToInsert], (err, result) => {
    if (err) throw err;
    console.log(`${result.affectedRows} records inserted successfully.`);
});
