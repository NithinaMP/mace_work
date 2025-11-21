import React from "react";

function Child(props){
    return(
        <div>
                <h2>This is from Child Class</h2>

        <button onClick={props.handleClick}>Click Me</button>
        </div>
    );
}
export default Child;