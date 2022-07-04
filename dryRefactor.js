function CheckError(){
  let error;
  if(OK(Run1())){
    if (OK(Run2())) {
      if (OK(Run3())) {
        if (OK(Run4())) {
        } else {
          error = Run4Err;          
        }
      } else {
        error = Run3Err
      }
    } else {
      error = Run2Err
    }
  }else{
    error = Run1Err
  }
}

// refactor
//nested condition
const refactorErrorCheck = () => {
  let error
  if (!OK(Run4)) {
    error = Run4Err
  }
}