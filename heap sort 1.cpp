/* Main function to do heap sort. This function uses buildHeap()
   and heapify()

void heapSort(int arr[], int n)  {
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
} */

void heapify(int arr[], int n, int i)  {

      int largest = i;
      int left = 2*i+1;
      int right = 2*i+2;

      if(left < n && arr[left] > arr[largest])
      {
            largest = left;
      }
      if(right < n && arr[right] > arr[largest])
      {
          largest = right;
      }
      if(largest != i)
      {
          swap(arr[i], arr[largest]);
          heapify(arr, n, largest);
      }
}

// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n){
    for(int i=n/2-1; i>=0; i--)
    {
        heapify(arr, n, i);
    }
}

