function solution(n, apeach) {
    let maxDiff = 0;
    let ryanBest = Array(11).fill(0);
    let ryan = Array(11).fill(0);
    
    const isBest = (ryan) => {
        for(let i=10; i>=0; i--) {
            if(ryanBest[i] > ryan[i]) {
                return false;
            }
            else if(ryanBest[i] < ryan[i]) {
                return true;
            }
        }
    }
    
    const getDiff = (ryan) => {
        let ryanScore = 0;
        let apeachScore = 0;
        
        for(let i=0; i<11; i++) {
            if(ryan[i] > apeach[i]) {
                ryanScore += 10 - i;
            }
            else if(apeach[i] > 0) {
                apeachScore += 10 - i;
            }
        }
        
        return ryanScore - apeachScore;
    }
    
    const shot = (idx, arrow, ryan) => {
        if(arrow === 0 || idx > 10) {
            let diff = getDiff(ryan);

            if(diff >= maxDiff) {
                if(diff === maxDiff && !isBest(ryan)){
                    return;
                }
                
                ryan[10] += arrow;
                maxDiff = diff
                ryanBest = [...ryan];
                ryan[10] -= arrow;
            }
            return;
        }
        
        if(apeach[idx] < arrow) {
            ryan[idx] += apeach[idx] + 1;
            shot(idx + 1, arrow - ryan[idx], ryan);
            ryan[idx] -= apeach[idx] + 1;
        }
    
        shot(idx + 1, arrow, ryan)
    }
    
    shot(0, n, ryan);
    return maxDiff > 0 ? ryanBest : [-1];
}