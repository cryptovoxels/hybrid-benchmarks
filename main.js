const { performance } = require('perf_hooks')
const Vector3 = require('babylonjs').Vector3
const sortBy = require('lodash.sortby')

function r () {
  return Math.random() * 800 - 400
}

function main () {
  let iterations = 250;

  let parcels = []

  for (let i = 0; i < 3500; i++) {
    let v = new Vector3(r(), r(), r())
    parcels.push(v);
  }

  let t = performance.now()
  let sorted

  for (let i=0; i < iterations; ++i) {
    let camera = new Vector3(r(), r(), r())

    sorted = sortBy(parcels, p => Vector3.DistanceSquared(camera, p))
    
    process.stdout.write(sorted[0].x.toFixed(2) + ", ")
  }

  console.log(sorted[0].x);

  let t2 = performance.now()

  console.log('Time taken: ' + ((t2 - t) / iterations).toFixed(2) + 'ms')
}

main()