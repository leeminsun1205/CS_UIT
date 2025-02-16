import sys
import time
import pandas as pd
import numpy as np
start = time.time()
#Em co dung chat gpt de tham khao cu phap
data = pd.read_csv(sys.stdin, encoding = 'unicode_escape', encoding_errors = 'replace', usecols=['CustomerID', 'InvoiceDate']).dropna()
data['InvoiceDate'] = pd.to_datetime(data['InvoiceDate'])
data = data.sort_values(by=['CustomerID', 'InvoiceDate'], ascending=[True, False]).drop_duplicates(subset='CustomerID', keep='first')
date_min = (data['InvoiceDate']).min()
data['score'] = (data['InvoiceDate'] - date_min).dt.days
print(data[['CustomerID', 'score']].to_string(index=False, justify='right'))
print(time.time()-start)
