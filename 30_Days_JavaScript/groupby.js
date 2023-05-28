/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    const retobj = {};

    for(const item of this)
    {
        const key = fn(item);
        if(key in retobj)
        {
            retobj[key].push(item);
        }
        else
        {
            retobj[key] = [item];
        }
    }
    return retobj;
    
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
