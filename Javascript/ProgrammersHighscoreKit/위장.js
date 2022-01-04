'usestrict';

function calculateCombination(hashmap) {
  let result = 1;

  hashmap.forEach((element) => {
    result *= element + 1;
  });

  return result - 1;
}

function setHashmap(array) {
  let hashMap = new Map();

  array.forEach((element) => {
    let key = element[1];

    if (hashMap.get(key) == undefined) {
      hashMap.set(key, 1);
    } else {
      hashMap.set(key, hashMap.get(key) + 1);
    }
  });

  return hashMap;
}

function solution(clothes) {
  let clothHashmap = setHashmap(clothes);
  return calculateCombination(clothHashmap);
}
