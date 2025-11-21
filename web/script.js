// function validateForm(){
// const username= document.getElementById("username");
// const email= document.getElementById("email");
// const password= document.getElementById("password");

// usernameError.textContent='';
// emailError.textContent='';
// passwordError.textContent='';

// let isValid=true;
// if (username.value.trim()=== ''){
// usernameError.textContent = "username is required";
// isValid = false;
// }
// elseif(username.value.length <3){
// usernameError.textContent = "username mustbe atleast 3 characters required";
// isValid = false;
// }
// const emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
// if (email.value.trim()===''){
// emailError.textContent = "email is required";
// isValid = false;
// }
// elseif(!emailPattern.test(email.value)){
// emailError.textContent = "please enter valid email address";
// isValid = false;
// }
// if (password.value.trim()=== ''){
// passwordError.textContent = "password is required";
// isValid = false;
// }
// elseif(password.value.length <3){
// passwordError.textContent = "password mustbe atleast 8 characters required";
// isValid = false;
// }
// }




// document.addEventListener('DOMContentLoaded', function() {
//   const form = document.getElementById('registrationForm');
//   const username = document.getElementById('username');
//   const email = document.getElementById('email');
//   const password = document.getElementById('password');
//   const password2 = document.getElementById('password2');

//   form.addEventListener('submit', function(e) {
//     e.preventDefault(); // Prevents the form from submitting

//     // Resetting previous error messages
//     const errorMessages = document.querySelectorAll('.error');
//     errorMessages.forEach(msg => msg.textContent = '');

//     let isValid = true;

//     // Validate Username
//     if (username.value.trim() === '') {
//       setError(username, 'Username is required');
//       isValid = false;
//     } else if (username.value.length < 3) {
//       setError(username, 'Username must be at least 3 characters');
//       isValid = false;
//     }

//     // Validate Email
//     if (email.value.trim() === '') {
//       setError(email, 'Email is required');
//       isValid = false;
//     } else if (!isValidEmail(email.value)) {
//       setError(email, 'Please enter a valid email address');
//       isValid = false;
//     }

//     // Validate Password
//     if (password.value.trim() === '') {
//       setError(password, 'Password is required');
//       isValid = false;
//     } else if (password.value.length < 6) {
//       setError(password, 'Password must be at least 6 characters');
//       isValid = false;
//     }

//     // Validate Password Confirmation
//     if (password2.value.trim() === '') {
//       setError(password2, 'Please confirm your password');
//       isValid = false;
//     } else if (password.value !== password2.value) {
//       setError(password2, 'Passwords do not match');
//       isValid = false;
//     }

//     // If all checks pass, submit the form
//     if (isValid) {
//       alert('Registration successful!'); // Or you can submit the form: form.submit();
//       form.reset();
//     }
//   });

//   // Helper function to display error messages
//   function setError(element, message) {
//     const errorElement = element.nextElementSibling;
//     errorElement.textContent = message;
//   }

//   // Helper function to validate email format using regex
//   function isValidEmail(email) {
//     const re = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
//     return re.test(String(email).toLowerCase());
//   }
// });



document.addEventListener('DOMContentLoaded', () => {
    const form = document.getElementById('registrationForm');
    const formElements = form.querySelectorAll('input');

    // Add event listeners for real-time validation
    formElements.forEach(input => {
        input.addEventListener('input', () => validateField(input));
    });

    // Handle form submission validation
    form.addEventListener('submit', (e) => {
        e.preventDefault();
        
        const formIsValid = validateForm();
        if (formIsValid) {
            alert('Form submitted successfully!');
            form.reset();
        } else {
            alert('Please fix the errors in the form.');
        }
    });

    /**
     * Validates all form fields on submit.
     * @returns {boolean} True if the entire form is valid, false otherwise.
     */
    function validateForm() {
        let allFieldsValid = true;
        formElements.forEach(input => {
            if (!validateField(input)) {
                allFieldsValid = false;
            }
        });
        return allFieldsValid;
    }

    /**
     * Validates a single input field.
     * @param {HTMLInputElement} inputElement The input to validate.
     * @returns {boolean} True if the input is valid, false otherwise.
     */
    function validateField(inputElement) {
        let errorMessage = '';

        // Check for validity using HTML5 built-in validation
        if (!inputElement.validity.valid) {
            errorMessage = getHTML5ValidationError(inputElement);
        }

        // Custom validation for password confirmation
        if (inputElement.id === 'confirmPassword' && inputElement.value !== document.getElementById('password').value) {
            errorMessage = 'Passwords do not match.';
        }
        
        // Display or clear the error message
        const errorSpan = inputElement.nextElementSibling;
        if (errorMessage) {
            errorSpan.textContent = errorMessage;
            inputElement.classList.add('invalid');
            return false;
        } else {
            errorSpan.textContent = '';
            inputElement.classList.remove('invalid');
            return true;
        }
    }

    /**
     * Gets a user-friendly error message based on HTML5 validation flags.
     * @param {HTMLInputElement} inputElement The input with a validation error.
     * @returns {string} The corresponding error message.
     */
    function getHTML5ValidationError(inputElement) {
        const validity = inputElement.validity;

        if (validity.valueMissing) {
            return 'This field is required.';
        }
        if (validity.typeMismatch && inputElement.type === 'email') {
            return 'Please enter a valid email address.';
        }
        if (validity.tooShort) {
            const minLength = inputElement.getAttribute('minlength');
            return `This field must be at least ${minLength} characters long.`;
        }
        if (validity.patternMismatch) {
            switch (inputElement.id) {
                case 'username':
                    return 'Username can only contain letters, numbers, and hyphens/underscores.';
                case 'password':
                    return 'Password must contain at least one uppercase letter, one lowercase letter, and one number.';
                default:
                    return 'Invalid format.';
            }
        }
        return '';
    }
});