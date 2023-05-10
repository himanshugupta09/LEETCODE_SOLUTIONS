/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let acc = init;
    for(const element of nums)
    {
        acc = fn(acc,element);
    }
    return acc;
    
};
