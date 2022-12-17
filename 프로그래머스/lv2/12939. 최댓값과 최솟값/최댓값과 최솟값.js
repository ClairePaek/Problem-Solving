function solution(s) {
    const number_array = s.split(' ').sort((a, b) => a - b);
    return `${number_array[0]} ${number_array[number_array.length-1]}`;
}