class HashTable:
    def __init__(self, cap: int):
        self.size = cap
        self.keys = [None] * self.size
        self.data = [None] * self.size

    def put(self, key, data):
        hashvalue = self.hash(key)
        if self.keys[hashvalue] == None:
            self.keys[hashvalue] = key
            self.data[hashvalue] = data
        else:
            if self.keys[hashvalue] == key:
                self.data[hashvalue] = data
            else:
                nextslot = self.rehash(hashvalue)
                while self.keys[nextslot] != None and self.keys[nextslot] != key:
                    nextslot = self.rehash(nextslot)

                if self.keys[nextslot] == None:
                    self.keys[nextslot] = key
                    self.data[nextslot] = data
                else:
                    self.data[nextslot] = data

    def hash(self, key) -> int:
        ans = 0
        for char in str(key):
            ans += ord(char)
        return ans % self.size

    def rehash(self, key) :
        ans = hash(str(key) + 'a')
        return ans % self.size


    def get(self, key):
        startkey = self.hash(key)
        #data = None
        stop = False
        found = False
        position = startkey
        while self.keys[position] != None and not found and not stop:
            if self.keys[position] == key:
                found = True
                #data = self.data[position]
            else:
                position = self.rehash(position)
                if position == startkey:
                    stop = True
        return position

    def __getitem__(self, key):
        return self.data[self.get(key)]

    def __setitem__(self, key, data):
        if(data == None):
            pos = self.get(key)
            self.data[pos] = None
            self.keys[pos] = None
            return
        self.put(key, data)

    def erase(self, key):
        self[key] = None

    # вывести все ячейки, включая пустые
    def displayAll(self):
        for i in range(len(self.data)):
            print(self.keys[i], " : ", self.data[i])

    # вывести НЕ пустые ячейки
    def display(self):
        for i in range(self.size):
            if (self.data[i] == None):
                continue
            print(self.keys[i], " : ", self.data[i])

    def append(self, key, data):
        self[key] = data

def main():
    h = HashTable(10)
   
    h.displayAll()

if __name__ == "__main__":
    main()