/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
    let nestA = true;
    let q;
    let dep = 0;

    while(nestA && dep < n)
    {
        q = [];

        for(let i=0;i<arr.length;i++)
        {
            if(Array.isArray(arr[i]))
            {
                q.push(...arr[i]);
                nestA = true;
            }
            else
            {
                q.push(arr[i]);
            }
        }
        arr = [...q];
        dep++;
    }
    return arr;
    
};
