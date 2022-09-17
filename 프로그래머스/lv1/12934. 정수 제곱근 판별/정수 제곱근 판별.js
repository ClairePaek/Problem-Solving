function solution(n) {
    const square = Math.sqrt(n);
    return Number.isInteger(square) ? (square+1)**2 : -1;
}