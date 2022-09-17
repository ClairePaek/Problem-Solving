function solution(arr) {
    const sum = arr.reduce((previous, current) => previous + current, 0);
    return sum / arr.length
}