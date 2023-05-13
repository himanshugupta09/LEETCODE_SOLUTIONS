/**
 * @param {Function} fn
 */
function memoize(fn) {
  const cache = new Map();
  return function() {
    let key = arguments[0];
    if (arguments[1]) {
      key += arguments[1] * 100001;
    }
    const result = cache.get(key);
    if (result !== undefined) {
      return result;
    }
    const functionOutput = fn.apply(null, arguments);
    cache.set(key, functionOutput);
    return functionOutput;
  }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
