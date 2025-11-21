import React from "react";
function Button(props){
    return(
        <button
        onClick={props.onClick}
        style={{
            backgroundColor: props.bg||"blue",
            color: "white",
        padding: "10px 20px",
        border: "none",
        borderRadius: "5px",
        margin: "5px",
        cursor: "pointer"
        }}
        >{props.text}</button>
    )
}
export default Button;