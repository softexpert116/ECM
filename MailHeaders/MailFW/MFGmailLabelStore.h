//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <Mail/MFLibraryStore.h>

@interface MFGmailLabelStore : MFLibraryStore
{
}

- (id)_allMailStore;
- (long long)_removeOurLabelFromMessages:(id)arg1;
- (id)lastSyncDate;
- (void)async_setFlagsFromDictionary:(id)arg1 forMessages:(id)arg2;
- (id)setFlagsFromDictionary:(id)arg1 forMessages:(id)arg2;
- (void)_messagesAddedToLibrary:(id)arg1;
- (void)deleteMessagesOlderThanNumberOfDays:(long long)arg1 compact:(BOOL)arg2;
- (void)deleteMessages:(id)arg1 moveToTrash:(BOOL)arg2;
- (id)moveMessages:(id)arg1 destinationMailboxURL:(id)arg2 userInitiated:(BOOL)arg3;
- (long long)undoAppendOfLibraryIDs:(id)arg1;
- (id)lastMessageWithHeaders:(id)arg1 inMailbox:(id)arg2;
- (BOOL)allowsOverwrite;

@end

