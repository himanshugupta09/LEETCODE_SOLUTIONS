/**
 * @param {any} obj
 * @param {any} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if(obj == null || obj == undefined || typeof classFunction != "function")
    {
        return false;
    }
    let cpp = Object.getPrototypeOf(obj);

    while(cpp != null)
    {
        if(cpp == classFunction.prototype)
        {
            return true;
        }
        cpp = Object.getPrototypeOf(cpp);
    }
    return false;
    
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */
