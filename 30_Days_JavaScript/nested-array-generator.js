/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function*(arr) {
    
    const stk = [arr];

    while(stk.length > 0)
    {
        const cur = stk.pop();

        if(!Array.isArray(cur))
        {
            yield cur;
            continue;
        }

        for(let i=cur.length-1;i >= 0;i--)
        {
            stk.push(cur[i]);
        }
    }
};

/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */
