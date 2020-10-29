//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class MFMailbox, NSArray, NSDictionary, NSEnumerator, NSMapTable, NSMutableDictionary, NSString, NSURL;

@interface MFBackupManager : NSObject
{
    NSMapTable *_mailboxBackupPaths;
    NSMutableDictionary *_mailboxesWithKnownContents;
    id _editableMessagesLock;
    id _timeMachineRestoreLock;
    BOOL _registeredForEditableMessageNotifications;
    MFMailbox *_topLevelRecoveryMailbox;
    NSDictionary *_lastSavedTableOfContents;
    NSArray *_messagePathsToRestore;
    NSURL *_mailboxDirectoryToRestore;
    NSString *_mailboxNameForRestoring;
}

+ (id)sharedManager;
@property(copy) NSString *mailboxNameForRestoring; // @synthesize mailboxNameForRestoring=_mailboxNameForRestoring;
@property(retain) NSURL *mailboxDirectoryToRestore; // @synthesize mailboxDirectoryToRestore=_mailboxDirectoryToRestore;
@property(copy) NSArray *messagePathsToRestore; // @synthesize messagePathsToRestore=_messagePathsToRestore;
@property BOOL registeredForEditableMessageNotifications; // @synthesize registeredForEditableMessageNotifications=_registeredForEditableMessageNotifications;
@property(copy) NSDictionary *lastSavedTableOfContents; // @synthesize lastSavedTableOfContents=_lastSavedTableOfContents;
@property(retain) MFMailbox *topLevelRecoveryMailbox; // @synthesize topLevelRecoveryMailbox=_topLevelRecoveryMailbox;
- (void).cxx_destruct;
@property(readonly, nonatomic) NSEnumerator *backupMailboxesEnumerator;
- (id)backupPathForMailbox:(id)arg1 pathsCache:(id)arg2;
- (id)_backupPathForMailbox:(id)arg1 withParentPath:(id)arg2 pathsCache:(id)arg3;
- (id)backupPathForMailbox:(id)arg1;
- (BOOL)saveTableOfContents:(id)arg1;
@property(readonly, copy, nonatomic) NSDictionary *tableOfContents;
- (void)_addMailbox:(id)arg1 toSection:(long long)arg2 sections:(id)arg3 messagePool:(id)arg4;
- (long long)_sectionForMailbox:(id)arg1;
- (id)_dictionaryForMessage:(id)arg1 includeRecipients:(BOOL)arg2;
- (id)_dictionaryForMailbox:(id)arg1 parent:(id)arg2 messagePool:(id)arg3;
- (id)_dictionaryForSection:(long long)arg1;
- (id)_expandedMailboxes:(id)arg1;
- (BOOL)_shouldSaveDisplayNameForMailbox:(id)arg1;
- (BOOL)shouldSaveMessagesForMailbox:(id)arg1;
- (id)_reducedPathFromFullPath:(id)arg1;
- (id)_reducedPathFromFullPath:(id)arg1 supportDirectory:(id)arg2;
- (id)_recoveryMailboxWithSuggestedName:(id)arg1 reuseMailbox:(BOOL)arg2;
- (BOOL)_restoreMailboxAtURL:(id)arg1 intoMailbox:(id)arg2 newMessages:(id)arg3;
- (BOOL)restoreMailboxesAtURL:(id)arg1 intoMailbox:(id)arg2 restoredMessages:(id)arg3;
- (id)restoreMailboxAtURL:(id)arg1 intoMailboxNamed:(id)arg2 postNotification:(BOOL)arg3;
- (void)prepareToRestoreMailboxAtURL:(id)arg1 intoMailboxNamed:(id)arg2;
- (id)restoreMessagesAtPaths:(id)arg1 intoMailboxNamed:(id)arg2 reuseMailbox:(BOOL)arg3 createdMailboxNamed:(id *)arg4 postNotification:(BOOL)arg5;
- (void)prepareToRestoreMessagesAtPaths:(id)arg1 intoMailboxNamed:(id)arg2;
@property(readonly) unsigned long long numberOfMessagesToBeRestored;
@property(readonly, copy) NSString *mailboxNameToBeRestored;
- (BOOL)hasPendingRestoreIsMailbox:(char *)arg1;
- (void)timeMachineRestoreFinished:(id)arg1;
- (void)performPendingRestore;
- (void)_setupDefaultTopLevelRecoveryMailbox;
- (void)editableMessagesWereDeleted:(id)arg1;
- (void)editableMessagesWereAdded:(id)arg1;
- (void)invalidateCaches;
- (void)dealloc;
- (id)init;

@end

