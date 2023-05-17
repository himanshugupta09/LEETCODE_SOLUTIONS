/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {
    async function  evalNex(){
        if(functions.length == 0) return;
        const fn = functions.shift();
        await fn();
        await evalNex();
    }
    const nPromis = Array(n).fill().map(evalNex);
    await Promise.all(nPromis);
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */
