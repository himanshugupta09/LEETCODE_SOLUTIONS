class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()
        op = []
        i, j = 0, 0
        while j < len(searchWord) + 1:
            temp = []

            for k in range(len(products)):
                a = products[k]

                if searchWord[i:j + 1] == a[i:j + 1]:
                    if len(temp) < 3:
                        temp.append(products[k])
                    else:
                        break

            op.append(temp)

            j += 1
        op = op[0:len(searchWord)]
        return op


