/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
    const chk = [];
    let idx  = 0;

    while(idx < arr.length)
    {
        let cnt = size;
        const temp = [];

        while(cnt --> 0 && idx < arr.length)
        {
            temp.push(arr[idx]);
            idx++;
        }
        chk.push(temp);

    }
    return chk;
};
