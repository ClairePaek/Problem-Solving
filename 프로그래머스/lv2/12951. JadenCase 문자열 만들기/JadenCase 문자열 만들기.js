function solution(s) {
    return s.split(' ').map(word => {
        const lowerCase = word.toLowerCase();
        return `${lowerCase.charAt(0).toLocaleUpperCase()}${lowerCase.slice(1)}`
    }).join(' ');
}