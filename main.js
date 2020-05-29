const { performance } = require('perf_hooks')
const Vector3 = require('babylonjs').Vector3
const sortBy = require('lodash.sortby')

function r () {
  return Math.random() * 800 - 400
}

function main () {
  let iterations = 1000;

  let parcels = []

  for (let i = 0; i < 35000; i++) {
    let v = new Vector3(r(), r(), r())
    parcels.push(v);
  }

  let t = performance.now()

  for (let i=0; i < iterations; ++i) {
    let camera = new Vector3(r(), r(), r())

    parcels.sort((a, b) => Vector3.DistanceSquared(a, camera) - Vector3.DistanceSquared(b, camera))
  
    // process.stdout.write(parcels[0].x.toFixed(2) + ", ")
  }

  console.log(parcels[0].x);

  let t2 = performance.now()

  console.log('Time taken: ' + ((t2 - t) / iterations).toFixed(2) + 'ms')
}

main()