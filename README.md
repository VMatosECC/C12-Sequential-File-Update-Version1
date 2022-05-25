read-an-old-master-record
read-a-transaction-record

while  not-at-end-of-BOTH-files

    if  master-key < transaction-key
    then
	write-master-file-from-master-record
	read-an-old-master-record
    else
    if  master-key = transaction-key
    then
	attempt-to-apply-transaction-to-master-record
	read-a-transaction-record
    else 
    if  master-key > transaction-key
    then
	attempt-to-add-transaction-record
	read-a-transaction-record
    end-if end-if
end-while
![image](https://user-images.githubusercontent.com/99844537/170177074-6dc783d0-8dc2-4eac-9b80-ffc387a6e072.png)

COBOL STYLE  

read-an-old-master-record
   READ  MASTER-FILE  INTO  MASTER-RECORD-WS
         AT END MOVE  HIGH-VALUES  TO  MASTER-KEY.end read-old-master-record.
![image](https://user-images.githubusercontent.com/99844537/170177100-a14d47e8-f1e6-44df-a4ea-4f0a5fddcb32.png)

