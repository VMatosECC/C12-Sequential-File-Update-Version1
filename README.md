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

---------------------------------------------------------
read-an-old-master-record
   READ  MASTER-FILE  INTO  MASTER-RECORD-WS
         AT END MOVE  HIGH-VALUES  TO  MASTER-KEY.
end read-old-master-record.

