# C12-Sequential-File-Update-Version1

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

COBOL STYLE  

read-an-old-master-record
   READ  MASTER-FILE  INTO  MASTER-RECORD-WS
         AT END MOVE  HIGH-VALUES  TO  MASTER-KEY.
end read-old-master-record.

![image](https://user-images.githubusercontent.com/99844537/170174821-6d125bcd-2fa2-4a80-afbc-334585629a1d.png)

![image](https://user-images.githubusercontent.com/99844537/170174602-eac3a474-9d7f-40f6-97ff-cf702789e4c4.png)
