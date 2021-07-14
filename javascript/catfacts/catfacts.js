const fetch = require('node-fetch');

(async () => { // Wrapped in an immediately executed, asynchronous, anonymous function for demonstration purposes
    const res = await fetch('https://catfact.ninja/fact'); // Fetch and await the response
    const data = await res.json(); // Parse as JSON
    console.log(data.fact); // Then log the fact
})();
