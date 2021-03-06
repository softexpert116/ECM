//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import <MailCore/MCActivityDelegate-Protocol.h>
#import <MailCore/MCHandlerDelegate-Protocol.h>
#import <MailCore/MCTaskListDelegate-Protocol.h>

@class MCTaskList, NSArray, NSMutableArray, NSMutableSet, NSOperationQueue, NSString;

@interface MCTaskManager : NSObject <MCTaskListDelegate, MCHandlerDelegate, MCActivityDelegate>
{
    NSMutableArray *_networkHandlers;
    NSMutableArray *_persistenceHandlers;
    NSMutableSet *_handlersCleaningUp;
    NSMutableSet *_activities;
    NSMutableSet *_bodyTrackers;
    NSMutableArray *_terminationBlocks;
    BOOL _hasActivity;
    BOOL _reassignTasksWillRun;
    NSOperationQueue *_serializationQueue;
    unsigned long long _maximumNetworkHandlers;
    unsigned long long _maximumPersistenceHandlers;
    MCTaskList *_taskList;
}

@property(readonly, nonatomic) MCTaskList *taskList; // @synthesize taskList=_taskList;
@property BOOL reassignTasksWillRun; // @synthesize reassignTasksWillRun=_reassignTasksWillRun;
@property BOOL hasActivity; // @synthesize hasActivity=_hasActivity;
@property unsigned long long maximumPersistenceHandlers; // @synthesize maximumPersistenceHandlers=_maximumPersistenceHandlers;
@property unsigned long long maximumNetworkHandlers; // @synthesize maximumNetworkHandlers=_maximumNetworkHandlers;
@property(readonly, nonatomic) NSOperationQueue *serializationQueue; // @synthesize serializationQueue=_serializationQueue;
- (void).cxx_destruct;
@property(readonly, nonatomic) BOOL networkIsLimited;
- (void)bodyTracker:(id)arg1 didCacheBodiesForMessages:(id)arg2;
- (void)handlerDidCleanUp:(id)arg1;
- (void)handler:(id)arg1 didFinishOperation:(id)arg2;
- (void)resetNetworkHandlers;
- (void)cleanUp;
- (void)terminate:(CDUnknownBlockType)arg1;
- (id)newBodyFetchContext;
- (void)goOffline;
- (void)activity:(id)arg1 didEncounterError:(id)arg2;
- (void)activityDidFinish:(id)arg1;
- (void)addActivity:(id)arg1;
- (void)taskListDidChange:(id)arg1;
- (void)assignIdleTasks;
- (void)assignActiveTasks;
- (void)adjustHandlers;
@property(readonly, copy, nonatomic) NSArray *orderedPersistenceHandlers;
@property(readonly, copy, nonatomic) NSArray *orderedNetworkHandlers;
- (void)_reassignTasks;
- (void)tasksNeedAssignment;
- (void)removePersistenceHandler:(id)arg1;
- (void)addPersistenceHandler:(id)arg1;
- (void)removeNetworkHandler:(id)arg1;
- (void)failedToCreateNetworkHandler;
- (void)addNetworkHandler:(id)arg1;
@property(readonly, copy, nonatomic) NSArray *persistenceHandlers;
@property(readonly, copy, nonatomic) NSArray *networkHandlers;
@property(readonly, nonatomic) BOOL isInSerializationQueue;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
@property(readonly, nonatomic) NSOperationQueue *utilityQueue;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

