// Round a number based on a given number of digits
const round = (n, decimals = 0) => {
  // firstly, check that input is a number or not.
  if (typeof n !== 'number') {
    return 'not a number.'
  }
  return Number(`${Math.round(`${n}e${decimals}`)}e-${decimals}`)
}

console.log(round(1.234567, 4))
