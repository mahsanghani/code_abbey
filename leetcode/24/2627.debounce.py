#
# @lc app=leetcode id=2627 lang=JavaScript
#
# [2627] Debounce
#
# @lc code=start
# /**
#  * @param {Function} fn
#  * @param {number} t milliseconds
#  * @return {Function}
#  */
var debounce = function(fn, t = 1000) {
    let timer;
    return function(...args) {
        clearTimeout(timer);
        timer = setTimeout(() => fn(...args), t);
    }
};
# /**
#  * const log = debounce(console.log, 100);
#  * log('Hello'); // cancelled
#  * log('Hello'); // cancelled
#  * log('Hello'); // Logged at t=100ms
#  */
# @lc code=end

