'''
0.access the site:
https://developers.google.com/gmail/api/quickstart/python
1.Enable the Gmail API in the site
credentials.json will be created.
2.run the following command:
$ pip install --upgrade google-api-python-client google-auth-httplib2 google-auth-oauthlib
3.download gmailcheck.py:
https://github.com/ytakefuji/IoT/blob/master/gmailcheck.py
4.run gmailcheck.py
$ python gmailcheck.py
it should show the number of unread massages.
'''
from googleapiclient.discovery import build
from httplib2 import Http
from oauth2client import file, client, tools

SCOPES = 'https://www.googleapis.com/auth/gmail.readonly'

def Unread(service, user_id, query=''):
  try:
    response = service.users().messages().list(userId=user_id,
                                               q=query).execute()
    messages = []
    if 'messages' in response:
      messages.extend(response['messages'])
    while 'nextPageToken' in response:
      page_token = response['nextPageToken']
      response = service.users().messages().list(userId=user_id, q=query,
                                         pageToken=page_token).execute()
      messages.extend(response['messages'])
    return messages
  except:
    print('An error occurred:')

def main():
   
    store = file.Storage('token.json')
    creds = store.get()
    if not creds or creds.invalid:
        flow = client.flow_from_clientsecrets('credentials.json', SCOPES)
        creds = tools.run_flow(flow, store)
    service = build('gmail', 'v1', http=creds.authorize(Http()))
    
    results = service.users().messages().list(userId='me',labelIds = ['INBOX']).execute()
    messages = results.get('messages', [])

    if not messages:
        print("No messages found.")
    else:
        unread = len(Unread(service, "me", "label:unread category:primary"))
        print(unread)
if __name__ == '__main__':
    main()
