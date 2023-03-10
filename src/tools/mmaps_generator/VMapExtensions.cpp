/*
* This file is part of Project SkyFire https://www.projectskyfire.org. 
* See LICENSE.md file for Copyright information
*/

#include <vector>
#include "MapTree.h"
#include "VMapManager2.h"
#include "WorldModel.h"
#include "ModelInstance.h"

namespace VMAP
{
    // Need direct access to encapsulated VMAP data, so we add functions for MMAP generator
    // maybe add MapBuilder as friend to all of the below classes would be better?

    // declared in src/shared/vmap/MapTree.h
    void StaticMapTree::getModelInstances(ModelInstance* &models, uint32 &count)
    {
        models = iTreeValues;
        count = iNTreeValues;
    }

    // declared in src/shared/vmap/VMapManager2.h
    void VMapManager2::getInstanceMapTree(InstanceTreeMap &instanceMapTree)
    {
        instanceMapTree = iInstanceMapTrees;
    }

    // declared in src/shared/vmap/WorldModel.h
    void WorldModel::getGroupModels(std::vector<GroupModel> &groupModels)
    {
        groupModels = this->groupModels;
    }

    // declared in src/shared/vmap/WorldModel.h
    void GroupModel::getMeshData(std::vector<G3D::Vector3> &vertices, std::vector<MeshTriangle> &triangles, WmoLiquid* &liquid)
    {
        vertices = this->vertices;
        triangles = this->triangles;
        liquid = iLiquid;
    }

    // declared in src/shared/vmap/ModelInstance.h
    WorldModel* ModelInstance::getWorldModel()
    {
        return iModel;
    }

    // declared in src/shared/vmap/WorldModel.h
    void WmoLiquid::getPosInfo(uint32 &tilesX, uint32 &tilesY, G3D::Vector3 &corner) const
    {
        tilesX = iTilesX;
        tilesY = iTilesY;
        corner = iCorner;
    }
}
