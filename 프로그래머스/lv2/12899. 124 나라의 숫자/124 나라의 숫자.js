function solution(n) {
    let rule = [4, 1, 2];
    let answer = '';
    
    while(n > 0) {
        let mod = n % 3;
        answer = rule[mod] + answer;

        let divide = Math.floor(n / 3);
        n = mod === 0 ? divide - 1 : divide;
    }
    
    return answer;
}