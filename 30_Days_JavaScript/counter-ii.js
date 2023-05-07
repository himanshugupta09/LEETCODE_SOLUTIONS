/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */

class Counter
{
    constructor(init)
    {
        this.init = init;
        this.curCount = init;

    }
    increment()
    {
        this.curCount += 1;
        return this.curCount;
    }
    decrement()
    {
        this.curCount -= 1;
        return this.curCount;
    }

    reset()
    {
        this.curCount = this.init;
        return this.curCount;
    }

}

var createCounter = function(init) {
    return new Counter(init);
    
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
