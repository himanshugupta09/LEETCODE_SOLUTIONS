from heapq import heapify,heappush,heappop
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        heap = []
        heapify(heap)
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                heappush(heap,matrix[i][j])
        heapq.heapify(heap)
        heap.sort()
        return heap[k-1]
        #print(heap)
        i = 0
        '''while i < k:
            if i == k:
                print(heap[i])
                break
                
            else:
                i += 1
                
                #heapq.heapify(heap)
                print(heap)'''
        
        
        
