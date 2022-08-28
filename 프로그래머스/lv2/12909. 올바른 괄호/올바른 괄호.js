function solution(s){
    let openBracket = 0;
    
    for(let i=0; i<s.length; i++) {
        if(s[i] === '(') {
            openBracket += 1;
        }
        else if(s[i] === ')') {
            openBracket -= 1;
        }
        
        if(openBracket < 0) {
            return false;
        }
    }
    
    return openBracket === 0 ? true : false;
}