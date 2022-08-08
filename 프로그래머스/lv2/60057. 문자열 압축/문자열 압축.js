function solution(s) {
    if(s.length === 1) {
        return 1;
    }
    
    let answer = s.length;
    
    for(let i=Math.floor(s.length/2); i>0; i--) {
        let subString = s.substring(0, i);
        let length = s.length;
        let count = 1;
        
        for(let j=i; j+i<=s.length; j+=i) {
            let newSubString = s.substring(j, j+i);
            
            if(subString === newSubString) {
                length -= newSubString.length;
                count += 1;
            }
            else {
                if(count !== 1) {
                    length += getNumberStringLength(count);
                }
                
                count = 1;
                subString = newSubString;
            }
        }
        
        if(count !== 1) {
            length += getNumberStringLength(count);
        }
        
        answer = Math.min(length, answer);
    }
    
    return answer;
}

function getNumberStringLength(number) {
    return number.toString().length;
}