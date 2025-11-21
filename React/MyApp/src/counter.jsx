import React, { useEffect, useState } from "react";
function Counter(){
    const[count,setCount] = useState(0);
    useEffect(()=>{
        console.log("Count updated: ${count}");
    },[count]);
    const increment=()=>setCount(count+1);
    const decrement=()=>setCount(count-1);
    return (
        <div>
            <h2>Counter:{count}</h2>
            <button onClick={increment}>Increment</button>
            <button onClick={decrement}>Decrement</button>
        </div>
    );
}
export default Counter;