function matrixsum (m1, m2){
  mnew = []
  if (getDimensions(m1) === getDimensions(m2)){
    for(let a = 0; a < getDimensions(m1)[0]; a++){
      for(let b = 0; b < getDimensions(m1)[1]; b++){
        mnew[a][b]=m1[a][b]+m2[a][b]
      }
    }
    console.log (mnew)
    return(mnew)
  }
  else{
    console.log ("this operation is not possible. the dimensions are different.")
  }

}
[3:45 PM]
function getDimensions (matrix){
  xdimension = matrix[0].length;
  ydimension = matrix.length;
 return [xdimension,ydimension]
}
