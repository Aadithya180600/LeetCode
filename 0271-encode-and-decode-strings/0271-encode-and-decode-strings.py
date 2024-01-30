class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        encoded_strs = [i.encode().hex() for i in strs]
        # print(encoded_strs)
        # return " ".join(encoded_strs)
        s = ""
        for i in strs:
            for j in i:
                s+=(str(ord(j)))
                s+=" "
            s+="/"
        print(s)
        return s

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
         # decoded_strs = [i.decode().hex() for i in strs]
         # print(encoded_strs)
        l = []
        r = ""
        k = ""
        for i in s:
            if i==" ":
                r+=chr(int(k))
                k=""
            elif i == "/":
                l.append(r)
                r =""
                k = ""
            else:
                k+=i
        return l
                
        
        


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))