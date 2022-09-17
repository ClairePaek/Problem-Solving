function solution(s){
    let p_count = 0;
    let y_count = 0;
    
    [...s].forEach(x => {
        switch(x) {
            case 'p':
            case 'P':
                p_count += 1;
                break;
            case 'y':
            case 'Y':
                y_count += 1;
                break;
        }
    })
    
    return p_count === y_count;
}