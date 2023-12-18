<?php

// Initialize collection plan
require_once(APPROOT.'collectors/src/vSphereCollectionPlan.class.inc.php');
require_once(APPROOT.'core/orchestrator.class.inc.php');
Orchestrator::UseCollectionPlan('vSphereCollectionPlan');
