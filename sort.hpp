/**
 * Attempt at making an int array sorter bc vectors are bad
 * 
*/
int* arr_randomize(const int ARR_SIZE){
  int startArr[ARR_SIZE];
  int* pLEDArr = startArr;  
  for (int i = 0; i < ARR_SIZE; i++){
    pLEDArr[i] = random(256);
  }
  return pLEDArr;
}

int* arr_sorter_commit(int* pLEDArr, const int ARR_SIZE, int &currPos, int* pCurrMin, CRGB* leds){

  // Display steps
  /*
  cout << "Flashing indexes " << pCurrMin[0] << " and " << currPos << endl;
  cout << "Switching indexes vv" << endl;
  */

  // Actualy switch values
  int currVal = pLEDArr[currPos];
  pLEDArr[currPos] = pCurrMin[1];
  pLEDArr[pCurrMin[0]] = currVal;

  // Display change on strip
  for (int i = 0; i < ARR_SIZE; i++){
    leds[i] = CHSV(pLEDArr[i], 255, 255);
  }

  return pLEDArr;
}

int* arr_sorter_step(int* pLEDArr, const int ARR_SIZE, int &currPos, bool& doneSorting, CRGB* leds){
    // Compare current position with size of array
    if (currPos == ARR_SIZE){
        doneSorting = true;     // Done sorting. Return to create a new randomized array 
        return pLEDArr;
    }
    
    // Identify operation to be done. Store position and value to be switched in pCurrMin
    int* pCurrMin = new int[2];
    pCurrMin[0] = currPos;
    pCurrMin[1] = pLEDArr[currPos];
    for (int i = currPos; i < ARR_SIZE; i++){
        if (pLEDArr[i] < pCurrMin[1]){  // if current LED val has a lower val than the current lowest, store it as new lowest
            pCurrMin[0] = i;
            pCurrMin[1] = pLEDArr[i];
        }
    }

    // Display switch
    pLEDArr = arr_sorter_commit(pLEDArr, ARR_SIZE, currPos, pCurrMin, leds);

    // Update curr position by 1 for next sorting operation
    currPos++;

    return pLEDArr;
}

