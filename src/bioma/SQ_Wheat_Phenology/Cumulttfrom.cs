
using System;
using System.Collections.Generic;
using System.Linq;
using System.Xml;
using CRA.ModelLayer.MetadataTypes;
using CRA.ModelLayer.Core;
using CRA.ModelLayer.Strategy;
using System.Reflection;
using VarInfo=CRA.ModelLayer.Core.VarInfo;
using Preconditions=CRA.ModelLayer.Core.Preconditions;
using CRA.AgroManagement;       
using Phenology.DomainClass;
namespace Phenology.Strategies
{
    public class CumulTTFrom : IStrategyPhenology
    {
        public CumulTTFrom()
        {
            ModellingOptions mo0_0 = new ModellingOptions();
            //Parameters
            List<VarInfo> _parameters0_0 = new List<VarInfo>();
            mo0_0.Parameters=_parameters0_0;

            //Inputs
            List<PropertyDescription> _inputs0_0 = new List<PropertyDescription>();
            PropertyDescription pd1 = new PropertyDescription();
            pd1.DomainClassType = typeof(Phenology.DomainClass.PhenologyState);
            pd1.PropertyName = "calendarMoments";
            pd1.PropertyType = (Phenology.DomainClass.PhenologyStateVarInfo.calendarMoments).ValueType.TypeForCurrentValue;
            pd1.PropertyVarInfo =(Phenology.DomainClass.PhenologyStateVarInfo.calendarMoments);
            _inputs0_0.Add(pd1);
            PropertyDescription pd2 = new PropertyDescription();
            pd2.DomainClassType = typeof(Phenology.DomainClass.PhenologyState);
            pd2.PropertyName = "calendarCumuls";
            pd2.PropertyType = (Phenology.DomainClass.PhenologyStateVarInfo.calendarCumuls).ValueType.TypeForCurrentValue;
            pd2.PropertyVarInfo =(Phenology.DomainClass.PhenologyStateVarInfo.calendarCumuls);
            _inputs0_0.Add(pd2);
            PropertyDescription pd3 = new PropertyDescription();
            pd3.DomainClassType = typeof(Phenology.DomainClass.PhenologyAuxiliary);
            pd3.PropertyName = "cumulTT";
            pd3.PropertyType = (Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTT).ValueType.TypeForCurrentValue;
            pd3.PropertyVarInfo =(Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTT);
            _inputs0_0.Add(pd3);
            mo0_0.Inputs=_inputs0_0;

            //Outputs
            List<PropertyDescription> _outputs0_0 = new List<PropertyDescription>();
            PropertyDescription pd4 = new PropertyDescription();
            pd4.DomainClassType = typeof(Phenology.DomainClass.PhenologyAuxiliary);
            pd4.PropertyName = "cumulTTFromZC_65";
            pd4.PropertyType = (Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTTFromZC_65).ValueType.TypeForCurrentValue;
            pd4.PropertyVarInfo =(Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTTFromZC_65);
            _outputs0_0.Add(pd4);
            mo0_0.Outputs=_outputs0_0;PropertyDescription pd5 = new PropertyDescription();
            pd5.DomainClassType = typeof(Phenology.DomainClass.PhenologyAuxiliary);
            pd5.PropertyName = "cumulTTFromZC_39";
            pd5.PropertyType = (Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTTFromZC_39).ValueType.TypeForCurrentValue;
            pd5.PropertyVarInfo =(Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTTFromZC_39);
            _outputs0_0.Add(pd5);
            mo0_0.Outputs=_outputs0_0;PropertyDescription pd6 = new PropertyDescription();
            pd6.DomainClassType = typeof(Phenology.DomainClass.PhenologyAuxiliary);
            pd6.PropertyName = "cumulTTFromZC_91";
            pd6.PropertyType = (Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTTFromZC_91).ValueType.TypeForCurrentValue;
            pd6.PropertyVarInfo =(Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTTFromZC_91);
            _outputs0_0.Add(pd6);
            mo0_0.Outputs=_outputs0_0;
            //Associated strategies
            List<string> lAssStrat0_0 = new List<string>();
            mo0_0.AssociatedStrategies = lAssStrat0_0;
            //Adding the modeling options to the modeling options manager
            _modellingOptionsManager = new ModellingOptionsManager(mo0_0);
            SetStaticParametersVarInfoDefinitions();
            SetPublisherData();

        }

        public string Description
        {
            get { return "Calculate CumulTT " ;}
        }

        public string URL
        {
            get { return "" ;}
        }

        public string Domain
        {
            get { return "";}
        }

        public string ModelType
        {
            get { return "";}
        }

        public bool IsContext
        {
            get { return false;}
        }

        public IList<int> TimeStep
        {
            get
            {
                IList<int> ts = new List<int>();
                return ts;
            }
        }

        private  PublisherData _pd;
        public PublisherData PublisherData
        {
            get { return _pd;} 
        }

        private  void SetPublisherData()
        {
            _pd = new CRA.ModelLayer.MetadataTypes.PublisherData();
            _pd.Add("Creator", "Pierre Martre");
            _pd.Add("Date", "");
            _pd.Add("Publisher", "INRA Montpellier");
        }

        private ModellingOptionsManager _modellingOptionsManager;
        public ModellingOptionsManager ModellingOptionsManager
        {
            get { return _modellingOptionsManager; } 
        }

        public IEnumerable<Type> GetStrategyDomainClassesTypes()
        {
            return new List<Type>() {  typeof(Phenology.DomainClass.PhenologyState),  typeof(Phenology.DomainClass.PhenologyState), typeof(Phenology.DomainClass.PhenologyRate), typeof(Phenology.DomainClass.PhenologyAuxiliary), typeof(Phenology.DomainClass.PhenologyExogenous)};
        }

        // Getter and setters for the value of the parameters of the strategy. The actual parameters are stored into the ModelingOptionsManager of the strategy.


        public void SetParametersDefaultValue()
        {
            _modellingOptionsManager.SetParametersDefaultValue();
        }

        private static void SetStaticParametersVarInfoDefinitions()
        {
        }

        public string TestPostConditions(Phenology.DomainClass.PhenologyState s,Phenology.DomainClass.PhenologyState s1,Phenology.DomainClass.PhenologyRate r,Phenology.DomainClass.PhenologyAuxiliary a,Phenology.DomainClass.PhenologyExogenous ex,string callID)
        {
            try
            {
                //Set current values of the outputs to the static VarInfo representing the output properties of the domain classes
                Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTTFromZC_65.CurrentValue=a.cumulTTFromZC_65;
                Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTTFromZC_39.CurrentValue=a.cumulTTFromZC_39;
                Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTTFromZC_91.CurrentValue=a.cumulTTFromZC_91;
                ConditionsCollection prc = new ConditionsCollection();
                Preconditions pre = new Preconditions(); 
                RangeBasedCondition r4 = new RangeBasedCondition(Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTTFromZC_65);
                if(r4.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTTFromZC_65.ValueType)){prc.AddCondition(r4);}
                RangeBasedCondition r5 = new RangeBasedCondition(Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTTFromZC_39);
                if(r5.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTTFromZC_39.ValueType)){prc.AddCondition(r5);}
                RangeBasedCondition r6 = new RangeBasedCondition(Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTTFromZC_91);
                if(r6.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTTFromZC_91.ValueType)){prc.AddCondition(r6);}
                string postConditionsResult = pre.VerifyPostconditions(prc, callID); if (!string.IsNullOrEmpty(postConditionsResult)) { pre.TestsOut(postConditionsResult, true, "PostConditions errors in strategy " + this.GetType().Name); } return postConditionsResult;
            }
            catch (Exception exception)
            {
                string msg = ".Phenology, " + this.GetType().Name + ": Unhandled exception running post-condition test. ";
                throw new Exception(msg, exception);
            }
        }

        public string TestPreConditions(Phenology.DomainClass.PhenologyState s,Phenology.DomainClass.PhenologyState s1,Phenology.DomainClass.PhenologyRate r,Phenology.DomainClass.PhenologyAuxiliary a,Phenology.DomainClass.PhenologyExogenous ex,string callID)
        {
            try
            {
                //Set current values of the inputs to the static VarInfo representing the inputs properties of the domain classes
                Phenology.DomainClass.PhenologyStateVarInfo.calendarMoments.CurrentValue=s.calendarMoments;
                Phenology.DomainClass.PhenologyStateVarInfo.calendarCumuls.CurrentValue=s.calendarCumuls;
                Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTT.CurrentValue=a.cumulTT;
                ConditionsCollection prc = new ConditionsCollection();
                Preconditions pre = new Preconditions(); 
                RangeBasedCondition r1 = new RangeBasedCondition(Phenology.DomainClass.PhenologyStateVarInfo.calendarMoments);
                if(r1.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyStateVarInfo.calendarMoments.ValueType)){prc.AddCondition(r1);}
                RangeBasedCondition r2 = new RangeBasedCondition(Phenology.DomainClass.PhenologyStateVarInfo.calendarCumuls);
                if(r2.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyStateVarInfo.calendarCumuls.ValueType)){prc.AddCondition(r2);}
                RangeBasedCondition r3 = new RangeBasedCondition(Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTT);
                if(r3.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTT.ValueType)){prc.AddCondition(r3);}
                string preConditionsResult = pre.VerifyPreconditions(prc, callID); if (!string.IsNullOrEmpty(preConditionsResult)) { pre.TestsOut(preConditionsResult, true, "PreConditions errors in strategy " + this.GetType().Name); } return preConditionsResult;
            }
            catch (Exception exception)
            {
                string msg = ".Phenology, " + this.GetType().Name + ": Unhandled exception running pre-condition test. ";
                throw new Exception(msg, exception);
            }
        }

        public void Estimate(Phenology.DomainClass.PhenologyState s,Phenology.DomainClass.PhenologyState s1,Phenology.DomainClass.PhenologyRate r,Phenology.DomainClass.PhenologyAuxiliary a,Phenology.DomainClass.PhenologyExogenous ex)
        {
            try
            {
                CalculateModel(s, s1, r, a, ex);
            }
            catch (Exception exception)
            {
                string msg = "Error in component Phenology, strategy: " + this.GetType().Name + ": Unhandled exception running model. "+exception.GetType().FullName+" - "+exception.Message;
                throw new Exception(msg, exception);
            }
        }

        private void CalculateModel(Phenology.DomainClass.PhenologyState s, Phenology.DomainClass.PhenologyState s1, Phenology.DomainClass.PhenologyRate r, Phenology.DomainClass.PhenologyAuxiliary a, Phenology.DomainClass.PhenologyExogenous ex)
        {
            List<string> calendarMoments_t1 = s1.calendarMoments;
            List<double> calendarCumuls_t1 = s1.calendarCumuls;
            double cumulTT = a.cumulTT;
            double cumulTTFromZC_65;
            double cumulTTFromZC_39;
            double cumulTTFromZC_91;
            cumulTTFromZC_65 = 0.0d;
            cumulTTFromZC_39 = 0.0d;
            cumulTTFromZC_91 = 0.0d;
            if (calendarMoments_t1.Contains("Anthesis"))
            {
                cumulTTFromZC_65 = cumulTT - calendarCumuls_t1[calendarMoments_t1.IndexOf("Anthesis")];
            }
            if (calendarMoments_t1.Contains("FlagLeafLiguleJustVisible"))
            {
                cumulTTFromZC_39 = cumulTT - calendarCumuls_t1[calendarMoments_t1.IndexOf("FlagLeafLiguleJustVisible")];
            }
            if (calendarMoments_t1.Contains("EndGrainFilling"))
            {
                cumulTTFromZC_91 = cumulTT - calendarCumuls_t1[calendarMoments_t1.IndexOf("EndGrainFilling")];
            }
            a.cumulTTFromZC_65= cumulTTFromZC_65;
            a.cumulTTFromZC_39= cumulTTFromZC_39;
            a.cumulTTFromZC_91= cumulTTFromZC_91;
        }

    }
}