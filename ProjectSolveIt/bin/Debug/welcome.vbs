Dim message, sapi
message="Hey, My name is Synthetic i was designed to make calculating easier and fun!, It was my duty to welcome you all remember math is fun so have fun using me to solve problems!"
Set sapi=CreateObject("sapi.spvoice")

with sapi
       Set .voice = .getvoices.item(1)
       .Volume = 70
       .Rate = -1
   end with
sapi.Speak message