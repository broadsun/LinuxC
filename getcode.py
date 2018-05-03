import requests
import re
import sys
outdir=sys.argv[1]


url=sys.argv[2]
r = requests.get(url)
c = r.content

l=c.split("href=\"")
for le in l:
    if le.find(".c") != -1 and le.find(".c.html") == -1:
        sl=le.split("\">")
        rc= requests.get(url+sl[0])
        with open(outdir+"/"+sl[0], "w") as code:
           code.write(rc.content)
