const doSomething = () => new Promise((resolve, reject) => {
    resolve('Something is done!');
})

doSomething()
  .then((result) => {
    console.log('Got the first result.')
    return new Promise((resolve, reject) => {
        let i = 1;
        if (i === 1) {
            resolve(result)
        }
        else {
            reject(result)
        }
    })
  })
  .then((newResult) => {
    console.log('Got the second result.')
    return new Promise((resolve, reject) => {
        let j = 1;
        if (j === 1) {
            resolve(newResult);
        }
        else {
            reject(newResult);
        }
    });
  })
  .then((finalResult) => {
    console.log(`Got the final result: ${finalResult}`);
  })
  .catch(failureInfo => {
    console.log(`Something got wrong. Error info is : ${failureInfo}`)
  });

  doSomething();