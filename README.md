# redis reader
redis reader is a tool for redis resp message, the input is a string of resp message, the out put is complete or else and how many byte had processed. When the input has a resp message, registered function will called. 

Note: the goal for this idea is to see how many resp message in the input string, and will call registered function, in the registered function, it will not change the data in the input mssage. if the input message has in-complete resp message, it will read the resp messasge and return the processed message in the result.
For example: 
if the input message is "+OK\r\n+O", it will return 5 and in-complete.

Detail see example.

## dependancy
C++11




enjoy

Max
